
# 数据转换

### RunID

78Ni:  1010-1170

128Pd: 2020-2133 (rm 2049 2052)

136Sn: 3000-3122 (rm 3100)

123Rh: 4000-4043

115Nb: 4100-4125

81Cu:  5000-5138

### 1. combine ( RawData to CombineData )

cd 1combine

./nohup_run.sh run1 run2

注：对 Run 3000-3122 的 gamma 时间作了特殊修正和 dithering

### 2. builddecay ( CombineData to DecayData )

cd 2builddecay

./nohup_run.sh run1 run2

### 3. correct ( DecayData to CorrectData )

cd 3correct

./nohup_run.sh

### 4. seperate ( CorrectData to SeperateData )

cd 4seperate

./nohup_run.sh Z A



# 数据处理

### 布居了 isomer 的数据

117Tc 117Ru 122Pd 126Pd