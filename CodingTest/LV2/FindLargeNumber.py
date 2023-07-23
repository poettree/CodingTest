#information
#Time = 
#Description: 

#Ways
#1. 뒷수를 계속 검색해서 하는 방법
#2.
#3. 
#Optional1. 

#Answer 1
def solution(numbers):
    #define
    answer = [-1] * len(numbers) 
    stack = []
    
    #Pretreatment
    
    
    #1st Answer
    # #Main
    # for i in range(len(numbers)):
    #     if(numbers[i]==max(numbers)):
    #             answer.append(-1)
    #             continue
            
    #     for j in range(len(numbers[i+1:])):
    #         print('i: ', numbers[i])
    #         print('j: ', numbers[j+i+1])
            
    #         if (numbers[i] < numbers[j+i+1]):
    #             answer.append(numbers[j+i+1])
    #             break
            
    #         if ((j+i+1) == len(numbers)-1):
    #             answer.append(-1)
    #             break
            
    #     if(i == len(numbers)-1):
    #         answer.append(-1)
    
   

    for idx, number in enumerate(numbers):
        while stack and numbers[stack[-1]] < number:
            print('answer: ', answer)
            print('stack: ', stack)
            print('stack: ', numbers[stack[-1]])
            answer[stack.pop()] = number

        stack.append(idx)

                
    return answer
   
#Test Code
numbers = [9, 1, 5, 3, 6, 2]
print(solution(numbers))
