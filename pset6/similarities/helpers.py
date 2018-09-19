from enum import Enum


class Operation(Enum):
    """Operations"""

    DELETED = 1
    INSERTED = 2
    SUBSTITUTED = 3

    def __str__(self):
        return str(self.name.lower())


def distances(a, b):
    """Calculate edit distance from a to b"""

    # set 2d list[a][b]
    cost = [[(0, None)for j in range(len(b) + 1)]for i in range(len(a) + 1)]

    # add value for base case
    for i in range(1, len(a) + 1):
        cost[i][0] = (i, Operation.INSERTED)
    for j in range(1, len(b) + 1):
        cost[0][j] = (j, Operation.DELETED)

    # fill in other entries
    for i in range(1, len(a) + 1):
        for j in range(1, len(b) + 1):
            S_step, OP1 = cost[i - 1][j - 1]
            S_step += 1
            D_step, OP2 = cost[i - 1][j]
            D_step += 1
            I_step, OP3 = cost[i][j - 1]
            I_step += 1
            if a[i - 1] == b[j - 1]:
                S_step -= 1

            min_step = min(S_step, D_step, I_step)
            if S_step == min_step:
                cost[i][j] = (S_step, Operation.SUBSTITUTED)
            elif D_step == min_step:
                cost[i][j] = (D_step, Operation.DELETED)
            else:
                cost[i][j] = (I_step, Operation.INSERTED)
    return cost