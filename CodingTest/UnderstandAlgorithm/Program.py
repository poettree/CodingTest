import Sort_lists

class Sorter:
    def bubble_arr(arr):
        bubble = Sort_lists.Sort()
        
        bubble.setArray(arr)
        bubble.bubble_sort()
        
        return arr


print(Sorter.bubble([6,2,4,3]))