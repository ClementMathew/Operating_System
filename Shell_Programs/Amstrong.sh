echo "Enter the Number "
read n
function_ams (){
t=$n
s=0
b=0
c=10
while [ $n -gt $b ]
do
 r=$((n%c))
 i=$((r*r*r))
 s=$((s+i))
 n=$((n/c))
done
echo $s
if [ $s == $t ]
then
echo "Amstrong Number"
else
echo "Not an Amstrong Number"
fi
}
function_ams
