import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class Main {

    public static void main(String[] args) {
    	try (Scanner sc = new Scanner(System.in)){
			int n = sc.nextInt();
			List<Integer> l = new ArrayList<Integer>();
			for (int i=1; i<n+1; i++) l.add(i);  //1からnまで入る文字列を作成
			List<List<Integer>>list = new ArrayList<List<Integer>>();
			permutation2(list,l,new ArrayList<Integer>());
    	}
    }


static List<List<Integer>> permutation2(List<List<Integer>>list,List<Integer> input, List<Integer> ans) {  //順列で範囲の順番をすべて計算
			if (input.size() <= 1) {
				List<Integer> l = new ArrayList<Integer>(ans); //最後の数字はここでくっつく
				//for (int i=0; i<l.size(); i++) System.out.print("A" +l.get(i) + " ");
				l.addAll(input);
				//for (int i=0; i<input.size(); i++) System.out.print("I" + input.get(i) + " ");
				//System.out.println();
				list.add(l);  //listに組み合わせを追加
			} else {
				for (int i=0; i<input.size(); i++) {  //inputの1、2、3…個目を分離して、残りの方に挿入する
					List<Integer> i1 = new ArrayList<Integer>();
					for (int j=0; j<i;j++) i1.add(input.get(j));
					for (int j=i+1; j<input.size();j++) i1.add(input.get(j));
					List<Integer> i2 = new ArrayList<Integer>(ans);
					i2.add(input.get(i));
					permutation2(list ,i1, i2); //空白を入れる
				}
			}
				return list;
	}
}
