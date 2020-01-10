brack_seq=input()

memo=[['-1' for i in range(len(brack_seq))] for j in range(len(brack_seq))]

def calc(seq, l, r):
    if l>r :
        return ''
    elif memo[l][r]!='-1':
        return memo[l][r]
    elif l==r:
        memo[l][r]='()' if seq[l]==')' or seq[l]=='(' else '[]'
    elif seq[l]==')':
        memo[l][r]='()' + calc(seq, l+1, r)
    elif seq[l]==']':
        memo[l][r]='[]' + calc(seq, l+1, r)
    elif seq[l]=='(':
        ans='()' + calc(seq, l+1, r)
        for i in range(l+1, r+1):
            if seq[i]==')':
                cur='(' + calc(seq, l+1,i-1) + ')' + calc(seq, i+1, r)
                if len(cur) < len(ans):
                    ans=cur
        memo[l][r]= ans
    else:
        ans='[]' + calc(seq, l+1, r)
        for i in range(l+1, r+1):
            if seq[i]==']':
                cur='[' + calc(seq, l+1,i-1) + ']' + calc(seq, i+1, r)
                if len(cur) < len(ans):
                    ans=cur
        memo[l][r]=ans
    return memo[l][r]

print(calc(brack_seq, 0, len(brack_seq)-1))
    
