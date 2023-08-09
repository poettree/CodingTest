class Sort: 
    __array = []
    
    def setArray(self,arr):
        self.__array = arr
        return self.__array
        
    
    def bubble_sort(self):
        arr = self.__array
        for i in range(len(arr) - 1, 0, -1):
            for j in range(i):
                if arr[j] > arr[j + 1]:
                    arr[j], arr[j + 1] = arr[j + 1], arr[j]
        self.__array = arr
        return self.__array
    
    def selection_sort(self):
        #region Performance Detail
            #Worth case performance: O(n^2)
            #Best case performance: O(n^2)
            #Average case performance: O(n^2)
            #Worth case space complexity: O(n) total, O(1) auxiliary
        #endregion
        
        arr = self.__array
        
        # Traverse through all array elements
        for i in range(len(arr)):
            
            # Find the minimum element in remaining
            # unsorted array
            min_idx = i
            for j in range(i+1, len(arr)):
                if arr[min_idx] > arr[j]:
                    min_idx = j
                    
            # Swap the found minimum element with
            # the first element       
            arr[i], arr[min_idx] = arr[min_idx], arr[i]
            
        self.__array = arr
        return self.__array
    
    def insertion_sort(self):
        #region Performance Detail
            #Worth case performance: O(n)
            #Best case performance: O(n^2)
            #Average case performance: O(n^2)
            #Worth case space complexity: O(1)
        #endregion
        arr = self.__array
        
        for step in range(1, len(arr)):
            key = arr[step]
            j = step - 1
        
            # Compare key with each element on the left of it until an element smaller than it is found
            # For descending order, change key<arr[j] to key>arr[j].        
            while j >= 0 and key < arr[j]:
                arr[j + 1] = arr[j]
                j = j - 1
            
            # Place key at after the element just smaller than it.
            arr[j + 1] = key
        
        self.__array = arr
        return self.__array
    
    
    def merge_sort(self):
        #region Performance Detail
            #Worth case performance: O(n*log n)
            #Best case performance: O(n*log n)
            #Average case performance: O(n*log n)
            #Worth case space complexity: O(n)
        #endregion
        arr = self.__array
        
        if len(arr) > 1:
            #  r is the point where the arr is divided into two subarrays
            r = len(arr)//2
            L = arr[:r]
            M = arr[r:]

            # Sort the two halves
            self.merge_sort(L)
            self.merge_sort(M)

            i = j = k = 0

            # Until we reach either end of either L or M, pick larger among
            # elements L and M and place them in the correct position at A[p..r]
            while i < len(L) and j < len(M):
                if L[i] < M[j]:
                    arr[k] = L[i]
                    i += 1
                else:
                    arr[k] = M[j]
                    j += 1
                k += 1

            # When we run out of elements in either L or M,
            # pick up the remaining elements and put in A[p..r]
            while i < len(L):
                arr[k] = L[i]
                i += 1
                k += 1

            while j < len(M):
                arr[k] = M[j]
                j += 1
                k += 1
        
        self.__array = arr
        return self.__array