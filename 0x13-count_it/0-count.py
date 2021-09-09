#!/usr/bin/python3
"Count it "

import requests
import collections


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
    new_return = {}
    all_sort = collections.Counter(all_list)
    for x in sorted(word_list):
        if (x.lower() in all_sort):
            print("{}: {}".format(x.lower(), all_sort[x.lower()]))
            new_return[x.lower()] = all_sort[x.lower()]
    
    return new_return