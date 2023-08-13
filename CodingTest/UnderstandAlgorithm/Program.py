import Sort_lists

class Sorter:
    def bubble_arr(arr):
        bubble = Sort_lists.Sort()
        bubble.setArray(arr)
        bubble.bubble_sort()
        
        return arr
    
    def selection_arr(arr):
        selection = Sort_lists.Sort()
        selection.setArray(arr)
        selection.selection_sort()
        
        return arr
    
    def insertion_arr(arr):
        insertion = Sort_lists.Sort()
        insertion.setArray(arr)
        insertion.insertion_sort()
        
        return arr
    
    def merge_arr(arr):
        merge = Sort_lists.Sort()
        merge.setArray(arr)
        merge.merge_sort()
        
        return arr
    
    def quick_arr(arr):
            quick = Sort_lists.Sort()
            quick.setArray(arr)
            quick.quick_sort()
            
            return arr
array = [6,2,4,3]
print(Sorter.quick_arr(array))