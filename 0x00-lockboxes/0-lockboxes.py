#!/usr/bin/python3
"""method that determines if all the boxes can be opened"""


def canUnlockAll(boxes):
    """method that determines if all the boxes can be opened"""
    global keys
    keys = []
    if boxes:
        callback(boxes, 0)
    else:
        return False

    if len(boxes) == max(keys) + 1:
        return True
    else:
        return False


def callback(boxes, index):
    """ recursive function to call itself"""
    for key in boxes[index]:
        if key not in keys:
            keys.append(key)
            callback(boxes, key)


"""if __name__ == '__main__':
    boxes = [[1, 4], [2], [0, 4, 1], [3], [], [4, 1], [5, 6]]
     [[1], [2], [3], [4], []]
        [[1, 4, 6], [2], [0, 4, 1], [5, 6, 2], [3], [4, 1], [6]]
        [[1, 4], [2], [0, 4, 1], [3], [], [4, 1], [5, 6]]
        print(canUnlockAll(boxes))"""
