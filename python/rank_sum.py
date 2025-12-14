# code for Mann-Whitney U test
from scipy.stats import mannwhitneyu
# Take batch 1 and batch 2 data as per above example
batch_1 =[3, 4, 2, 6, 2, 5]
batch_2 =[9, 7, 5, 10, 8, 6]
  
# perform mann whitney test
stat, p_value = mannwhitneyu(batch_1, batch_2)
print('Statistics=%.2f, p=%.2f' % (stat, p_value))
# Level of significance
alpha = 0.05
# conclusion
if p_value < alpha:
    print('Reject Null Hypothesis (Significant difference between two samples)')
else:
    print('Do not Reject Null Hypothesis (No significant difference between two samples)')