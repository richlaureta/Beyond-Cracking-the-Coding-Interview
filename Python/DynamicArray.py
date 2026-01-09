class DynamicArray:
    #Problem 25.1 Implement Dynamic Array - Page 282 - 286
    
    def __init__(self):
        self.capacity = 10
        self.size = 0
        self.fixedArray = [None] * self.capacity
    
    def append(self, element):
        if self.size == self.capacity:
            self.increaseSize()
        self.fixedArray[self.size] = element
        self.size += 1
    
    def get(self, index):
        if index < 0 or index >= self.size:
            raise IndexError("Index is out of bounds.")
        return self.fixedArray[index]
    
    def set(self, index, element):
        if index < 0 or index >= self.size:
            raise IndexError("Index is out of bounds.")
        
        self.fixedArray[index] = element
    
    def getSize(self):
        return self.size
    
    def increaseSize(self):
        newCapacityArray = [None] * (self.capacity * 2)
        
        for index in range(self.size):
            newCapacityArray[index] = self.fixedArray[index]
        
        self.fixedArray = newCapacityArray
        self.capacity = self.capacity * 2
    
    def decreaseSize(self):
        newCapacityArray = [None] * (self.capacity//2)
        
        for index in range(self.size):
            newCapacityArray[index] = self.fixedArray[index]
        
        self.fixedArray = newCapacityArray
        self.capacity = self.capacity//2
    
    def popback(self):
        if self.size == 0:
            raise IndexError("The array is already empty.")
        
        self.size -= 1
        
        if self.size / self.capacity < 0.25 and self.capacity > 10:
            self.decreaseSize()
    
    def printDynamicArray(self):
        print("[", end ="")
        
        for index in range(self.size):
            if index == self.size - 1:
                print(self.fixedArray[index], end="")
                break
            print(self.fixedArray[index], end = ", ")
        
        print("]")
    
    def pop(self, popIndex):
        if popIndex < 0 or popIndex >= self.size:
            if self.size == 0:
                raise IndexError("Array is empty.")
            
            raise IndexError("Index is out of bounds.")
        
        poppedElement = self.fixedArray[popIndex]
        
        for index in range(popIndex + 1, self.size):
            self.fixedArray[index - 1] = self.fixedArray[index]
        
        self.size -= 1
        
        if self.size / self.capacity < 0.25 and self.capacity > 10:
            self.decreaseSize()
            
        return poppedElement
    
    def contains(self, element):
        if self.size == 0:
            raise IndexError("The array is empty.")
        
        for index in range(self.size):
            if element == self.fixedArray[index]:
                return True
            
        return False
        
if __name__ == "__main__":
    dynamicArray1 = DynamicArray()
    
    if dynamicArray1.contains(7):
        print("It is in the array.")
    else:
        print("It is not in the array.")