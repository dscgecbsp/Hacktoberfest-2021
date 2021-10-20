
def binary_Search(list,n,Beg,End):
    mid = int((Beg+End)/2)
    while n!=list[mid]:
        if(n == list[mid]):
            print('Element found at',mid,'Loc')
            break
        elif(n<list[mid]):
            End = mid-1
        elif(n>list[mid]):
            Beg = mid+1

new_list=[2,3,4,5,6,7,8,9]
Beg=0
End=len(new_list)-1
binary_Search(new_list,4,Beg,End)
