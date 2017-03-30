#!/usr/bin/env python
# encoding: utf-8

class Heap:
    def __init__(self, items=None):
        self.heaproom = items if items else []

    def insert(self, item):
        self.heaproom.append(item)
        bubble_node = len(self.heaproom)
        bubble_parent = bubble_node / 2
        while bubble_parent >= 1:
            if self.heap_orient[bubble_parent-1] < self.heap_orient[bubble_node-1]:
                self.heap_orient[bubble_parent-1], self.heap_orient[bubble_node-1] =\
                    self.heap_orient[bubble_node-1], self.heap_orient[bubble_parent-1]
                bubble_node = bubble_parent
                bubble_parent /= 2
            else:
                break

    def pop_max(self):
        poped = self.heaproom[0]
        self.heaproom[0] = self.heaproom.pop()
        hl = len(self.heaproom) # Heap Length
        dp = 1  # diving position
        lp, rp = dp * 2, dp * 2 + 1 # left child position, right ..
        while lp <= hl:
            mp = rp if rp <= hl and self.heaproom[rp-1] > self.heaproom[dp-1]\
                else dp # Maxium value position
            mp = lp if self.heaproom[lp-1] > self.heaproom[mp-1] else mp
            if mp != dp:
                self.heaproom[dp-1], self.heaproom[mp-1] =\
                    self.heaproom[mp-1], self.heaproom[dp-1]
                dp = mp
                lp, rp = dp * 2, dp * 2 + 1 # left child position, right ..
            else:
                break
        return poped

    def heap_maxify(self):
        hl = len(self.heaproom)
        for tp in reversed(range(1,len(self.heaproom)//2+1)): # target root position
            dp = tp  # diving position
            lp, rp = dp * 2, dp * 2 + 1 # left child position, right ..
            while lp <= hl:
                mp = rp if rp <= hl and self.heaproom[rp-1] > self.heaproom[dp-1]\
                    else dp # Maxium value position
                mp = lp if self.heaproom[lp-1] > self.heaproom[mp-1] else mp
                if mp != dp:
                    self.heaproom[dp-1], self.heaproom[mp-1] =\
                        self.heaproom[mp-1], self.heaproom[dp-1]
                    dp = mp
                    lp, rp = dp * 2, dp * 2 + 1 # left child position, right ..
                else:
                    break



a=list(range(1000))

from random import shuffle
shuffle(a)
print(a)
h = Heap(a)
h.heap_maxify()
