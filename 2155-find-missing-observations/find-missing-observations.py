class Solution:
    def missingRolls(self, rolls: List[int], mean: int, n: int) -> List[int]:
        m=len(rolls)
        tot_sum=mean*(m+n)
        missing_sum=tot_sum-sum(rolls)

        if (missing_sum)/6 >n or missing_sum<n:
            return []

        ans=[]

        while n:
            dice=min(6, missing_sum-n+1)
            ans.append(dice)
            missing_sum=missing_sum-dice
            n=n-1

        return ans