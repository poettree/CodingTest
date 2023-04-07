#information
#Time = 00:32:23
#Description: insert()와 pop() 또는 remove()등을 쓰지 않고, 딕셔너리로 등수를 매겨 업데이트하는 방식으로 사용

#Answer
def solution(players, callings):
    #Position : Index
    p_idx_dict = {player: i for i, player in enumerate(players)}
    #Index : Position
    idx_p_dict = {i:player for i, player in enumerate(players)}

    for playerName in callings:
        cur_idx = p_idx_dict[playerName] #Called Player
        pre_idx = cur_idx-1 #pre Called Player
        cur_player = playerName
        pre_player = idx_p_dict[pre_idx]

        p_idx_dict[cur_player] = pre_idx #current player be pre player index
        p_idx_dict[pre_player] = cur_idx #pre player be current player index

        idx_p_dict[pre_idx] = cur_player
        idx_p_dict[cur_idx] = pre_player #Update keys

    return list(idx_p_dict.values())

#Test Code
players = ["mumu", "soe", "poe", "kai", "mine"]
callings = ["kai", "soe", "kai", "mine", "mine"]
print(solution(players, callings))