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
        
        if self.size / self.capacity <= 0.25 and self.capacity > 10:
            self.decreaseSize()
    
    def printDynamicArray(self):
        print("[", end ="")
        
        for index in range(self.size):
            if index == self.size - 1:
                print(self.fixedArray[index], end="")
                break
            print(self.fixedArray[index], end = ", ")
        
        print("]")
        
if __name__ == "__main__":
    dynamicArray1 = DynamicArray()