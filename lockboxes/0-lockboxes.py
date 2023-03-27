#!/usr/bin/python3
"""method that determines if all the boxes can be opened"""


def canUnlockAll(boxes):
    """method that determines if all the boxes can be opened"""
    global keys
    global all_keys
    keys = []
    all_keys = []
    if boxes:
        callback(boxes, 0)
    else:
        return False
    all_keys = all_keys_check(boxes)

    for i in all_keys:
        if i not in keys:
            return False
    return True


def all_keys_check(boxes):
    if boxes:
        for i in range(len(boxes)):
            for j in range(len(boxes[i])):
                if boxes[i][j] not in all_keys:
                    all_keys.append(boxes[i][j])
        return(all_keys)


def callback(boxes, index):
    """ recursive function to call itself"""
    try:
        for key in boxes[index]:
            if key not in keys:
                keys.append(key)
                callback(boxes, key)
    except:
        pass
