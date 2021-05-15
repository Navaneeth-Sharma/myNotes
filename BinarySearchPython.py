
# Array (List)
nums = [1,3,5,6]

# The Function of Binary Search with Itterative Approach
def binary_search(arr, key):
    '''
    arr --> is the list or array
    key --> Element to Search for
    '''
    l = 0
    h = len(arr)
    mid = (l+h)//2
    
    
    while(l<h):
        if key>arr[mid]:
            l = mid+1
            mid = (l+h)//2
        if key<arr[mid]:
            h = mid-1
            mid = (l+h)//2
        else:
            return mid
     
     return -(l+1)



# Another Simple Array
A = [1,2,3,5,8]

# Binary Search Using Reccursive Approach
def recBin_search(l, h, key):
    '''
    l --> low index
    h --> high index
    key --> Element to search for
    '''
    if l==h:
        if A[l]==key:
            return l
        else:
            return -1
    else:
        mid=(l+h)//2
        if key==A[mid]:
            return mid
        if key<A[mid]:
            return recBin_search(l, mid-1, key)
        else:
            return recBin_search(mid+1, h, key)

#Give the Key Element 
print(recBin_search(0, len(A), key=3))

print(binary_search(nums, key=2))
