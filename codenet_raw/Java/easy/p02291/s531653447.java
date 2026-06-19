import java.util.Arrays;
import java.util.LinkedList;
import java.util.Random;
import java.util.Scanner;
import java.util.concurrent.SynchronousQueue;

public class Main {

	class P {
		double x, y;

		P(double x_, double y_) {
			x = x_;
			y = y_;
		}

		P add(P p) {
			return new P(x + p.x, y + p.y);
		}

		P sub(P p) {
			return new P(x - p.x, y - p.y);
		}

		P mul(double v) {
			return new P(x * v, y * v);
		}

		P div(double v) {
			return new P(x / v, y / v);
		}

		double dot(P p) {
			return x * p.x + y * p.y;
		}

		double det(P p) {
			return x * p.y - y * p.x;
		}

		double abs2() {
			return x * x + y * y;
		}

		double abs() {
			return Math.sqrt(abs2());
		}

		P norm() {
			return div(abs());
		}

		P rot90() {
			return new P(-y, x);
		}

		P proj(P src, P dst) {
			P p_sd = dst.sub(src).norm();
			return src.add(p_sd.mul(sub(src).dot(p_sd)));
		}

		P reflect(P src, P dst) {
			P middle = proj(src, dst);
			return add(middle.sub(this).mul(2));
		}
	}

	void run() {
		Scanner sc = new Scanner(System.in);
		P src = new P(sc.nextDouble(), sc.nextDouble());
		P dst = new P(sc.nextDouble(), sc.nextDouble());
		int q = sc.nextInt();
		while (q-- > 0) {
			P p = new P(sc.nextDouble(), sc.nextDouble());
			P x = p.reflect(src, dst);
			System.out.println(x.x + " " + x.y);
		}
	}

	public static void main(String[] args) {
		new Main().run();
	}

	static void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}

}