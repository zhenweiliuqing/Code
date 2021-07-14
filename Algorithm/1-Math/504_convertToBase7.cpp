// 这跟对123取余是一样的啊！！！
class Solution {
public:
    string convertToBase7(int num) {
        string res = "";
        bool flag = false;//负数标志
        if (num < 0){
            flag = true;
            num = -num;
        }
        //开始转换
        while (num != 0){
            res = char(num % 7 + '0') + res;
            num /= 7;
        }
        //判断是否是负数、空，进行修正
        if (flag){
            res = '-' + res;
        }
        else if (res == ""){
            res = "0";
        }
        return res;
    }
};

// 3-15
// 自己磨了半个小时才做出来 这哪行啊
class Solution {
public:
    string convertToBase7(int num) {
        string ans;
        if (num == 0)
            return "0";
        bool minus = false;
        if (num < 0) {
            minus = true;
            num = -num;
            ans += '-';
        }
        int i = 0;
        while (pow(7, i) <= num)
            i++;
        while (i != 0) {
            i--;
            // ans += x / pow(7, i) * pow(10, i);
            ans += to_string(int(num / pow(7, i)));
            num = num % int(pow(7, i));
        }
        return ans;
    }
};

