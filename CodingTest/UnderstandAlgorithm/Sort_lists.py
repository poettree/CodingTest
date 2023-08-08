class Sort: 
    __array = []
    
    def setArray(self,arr):
        self.__array = arr
        return self.__array
        
    
    def bubble_sort(self):
        for i in range(len(self.__array) - 1, 0, -1):
            for j in range(i):
                if self.__array[j] > self.__array[j + 1]:
                    self.__array[j], self.__array[j + 1] = self.__array[j + 1], self.__array[j]
        return self.__array