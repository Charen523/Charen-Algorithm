p,n=map(int,input().split())
a_n=list(map(int,input().split()))
a_n.sort()
acce=0
'''
for i in range(n):
    if p+a_n[i]<200:
        acce+=1
        p+=a_n[i]
    else:
        acce+=1
        break
'''
for i in range(n):
    if p<200:
        acce+=1
        p+=a_n[i]
    else:
        break
print(acce)