class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        
        # Idea :
        # use a stack and avoid the O(n^2) brute force solution
        # stk = [(temp_i,i)]
        # if i find k such that temp_k < temp_i (stk[-1]) 
        # there are multiple elements in the stack :
        # [(temp_i,i), (temp_k,k)] where k > i and so on
        # if i find an index j such that :
        # temp_j > temp_i --> res [i] = [j - i]
        # i check if temp_j than last stack element (stk[-1]) until stack is empty
        # if not i simply add the last tuple onto the stack
        # TC : O(n)
        # SC : O(n)
     
        indexed_temperatures = [[index,t] for index,t in enumerate(temperatures)]
        stk = []
        res = [0] * len(temperatures) 
        
        # if stk is empty add the tuple
        # if is not empty check if current temp is > than last temperatures 
        # loop while stk is not empty and current temp > stk[-1][0]

        for index,t in indexed_temperatures :

            if not stk:
                stk.append([t,index])
            else :
                while stk and t > stk[-1][0]:
                    res[stk[-1][1]] = index - stk[-1][1] 
                    stk.pop() 

                stk.append([t,index])
  
        return res
