#!/usr/bin/python3
"Count it "

import collections
import requests


def get_words(subreddit, all_list=[], after=None):
    """
    recursive get all the words in hot titles
    """
    req = requests.get("https://www.reddit.com/r/{}/hot.json?after={}".
                       format(subreddit, after),
                       headers={"User-agent": "agent"},
                       allow_redirects=False)
    if req.status_code != 200:
        return None
    after = req.json().get("data").get("after")
    if after is None:
        return all_list

    for child in req.json().get("data").get("children"):
        for word in child.get("data").get("title").split():
            all_list.append(word.lower())
    return get_words(subreddit, all_list, after)


def count_words(subreddit, word_list):
    """
    count specific words in subreddit hot titles
    """
    if subreddit is None or subreddit == "" or word_list is None:
        return None

    all_list = get_words(subreddit)
    if all_list is None:
        return None

    shown = {}
    all_sort = collections.Counter(all_list)
    for word in word_list:
        word_l = word.lower()
        if all_sort[word_l] > 0:
            if word in shown:
                shown[word] += shown[word]
            else:
                shown[word] = all_sort[word_l]

    for key, val in sorted(shown.items(),
                           key=lambda item: item[1], reverse=True):
        print("{}: {}".format(key, val))
