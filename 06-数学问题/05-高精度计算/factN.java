/*----------------------------------------------------------------
 *
 *   文件名称：_01fact_N.java
 *   创建日期：2021年03月10日 ---- 20时35分
 *   题    目：hdu1042
 *   算    法：高精度计算
 *   描    述：输入：N(0 <= N <= 10000)    输出：N!
 *
 ----------------------------------------------------------------*/

import java.math.BigInteger;
import java.util.*;

public class _01fact_N {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        while (input.hasNextInt()) {  //判断是否仍有int型输入
            int n = input.nextInt();  //输入int型变量n
            BigInteger res = BigInteger.ONE;
            for (int i = 1; i <= n; ++i)
                res = res.multiply(BigInteger.valueOf(i)); //BigInteger.valueOf(i)强制类型转换
            System.out.println(res);
        }
    }
}
