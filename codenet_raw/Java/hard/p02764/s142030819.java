import java.io.IOException;
import java.io.InputStream;
import java.util.NoSuchElementException;
import java.util.Objects;

public class Main {
    public static void main(String[] args) {
        FastScanner fsc = new FastScanner();
        int n = fsc.nextInt();
        int k = fsc.nextInt();
        int[][] xyc = new int[n][3];
        for (int i = 0; i < n; i++) {
            int x = fsc.nextInt();
            int y = fsc.nextInt();
            int c = fsc.nextInt();
            xyc[i][0] = x;
            xyc[i][1] = y;
            xyc[i][2] = c;
        }
        double fail = 0.0;
        double pass = 1e9;
        WL:while (pass - fail > Const.DELTA) {
            double x = (pass + fail) / 2;
            Circle[] c = new Circle[n];
            for (int i = 0; i < n; i++) {
                c[i] = new Circle(new Complex(xyc[i][0], xyc[i][1]), x / xyc[i][2]);
            }
            for (int i = 0; i < n; i++) {
                int cnt = 0;
                for (int j = 0; j < n; j++) {
                    if (c[j].inon(c[i].c)) {
                        cnt++;
                    }
                }
                if (cnt >= k) {
                    pass = x;
                    continue WL;
                }
            }
            for (int p = 0; p < n - 1; p++) {
                for (int q = p + 1; q < n; q++) {
                    for (Complex crs : Geometry.crossPoint(c[p], c[q])) {
                        int cnt = 0;
                        for (int j = 0; j < n; j++) {
                            if (c[j].inon(crs)) {
                                cnt++;
                            }
                        }
                        if (cnt >= k) {
                            pass = x;
                            continue WL;
                        }
                    }
                }
            }
            fail = x;
        }
        System.out.println(pass);
    }
}

class Geometry {
    private static double PI = Math.PI;

    public static double innerProduct(Complex u, Complex v) {
        return u.x * v.x + u.y + v.y;
    }

    public static double outerProductZ(Complex u, Complex v) {
        return u.x * v.y - u.y * v.x;
    }

    public static Complex internalDivision(Complex a, Complex b, int m, int n) {
        return Complex.div(Complex.add(Complex.mul(a, n), Complex.mul(b, m)), m + n);
    }

    public static Complex externalDivision(Complex a, Complex b, int m, int n) {
        return internalDivision(a, b, -m, n);
    }

    public static Complex pM(Complex a, Complex b) {
        return Complex.div(Complex.add(a, b), 2.);
    }

    public static Complex pG(Complex a, Complex b, Complex c) {
        return new Triangle(a, b, c).pG();
    }

    public static Complex pH(Complex a, Complex b, Complex c) {
        return new Triangle(a, b, c).pH();
    }

    public static Complex pI(Complex a, Complex b, Complex c) {
        return new Triangle(a, b, c).pI();
    }

    public static Complex pO(Complex a, Complex b, Complex c) {
        return new Triangle(a, b, c).pO();
    }

    public static Complex[] pIabc(Complex a, Complex b, Complex c) {
        return new Triangle(a, b, c).pIabc();
    }

    public static double arg(Complex a, Complex b, Complex c) {
        double arg = Complex.arg(Complex.div(Complex.sub(c, b), Complex.sub(a, b)));
        if (arg < 0) {
            arg *= -1.;
        }
        return arg;
    }

    public static boolean oneLine(Complex a, Complex b, Complex c) {
        if (a.equals(b) || b.equals(c) || c.equals(a)) {
            return true;
        }
        double arg = arg(a, b, c);
        return arg <= Const.DELTA || arg >= PI - Const.DELTA;
    }

    public static Complex crossPoint(Line l1, Line l2) {
        double p  = l1.a * l2.b - l2.a * l1.b;
        double qx = l1.b * l2.c - l2.b * l1.c;
        double qy = l2.a * l1.c - l1.a * l2.c;
        if (Math.abs(p) <= Const.DELTA) {
            if (Math.abs(qx) <= Const.DELTA && Math.abs(qy) <= Const.DELTA) {
                return Complex.NaN;
            } else {
                return null;
            }
        } else {
            double x = qx / p;
            double y = qy / p;
            if (l1.begin.x - Const.DELTA <= x && x <= l1.end.x + Const.DELTA && l2.begin.x - Const.DELTA <= x && x <= l2.end.x + Const.DELTA) {
                return new Complex(x, y);
            } else {
                return null;
            }
        }
    }

    public static Complex[] crossPoint(Circle c, Line l) {
        double d = l.a * c.c.x + l.b * c.c.y + l.c;
        double rt = c.r * c.r - d * d;
        if (rt < 0) {
            return new Complex[0];
        }
        rt = Math.sqrt(rt);
        double x1 = -l.a * d + l.b * rt + c.c.x;
        double x2 = -l.a * d - l.b * rt + c.c.x;
        double y1 = -l.b * d - l.a * rt + c.c.y;
        double y2 = -l.b * d + l.a * rt + c.c.y;
        Complex[] ret = {new Complex(x1, y1), new Complex(x2, y2)};
        return ret;
    }

    public static Complex[] crossPoint(Circle c1, Circle c2) {
        double x = c2.c.x - c1.c.x;
        double y = c2.c.y - c1.c.y;
        double xsq = x * x;
        double ysq = y * y;
        double r1sq = c1.r * c1.r;
        double r2sq = c2.r * c2.r;
        double a = (xsq + ysq + r1sq - r2sq) / 2;
        double rt = (xsq + ysq) * r1sq - a * a;
        if (rt < 0) {
            return new Complex[0];
        }
        rt = Math.sqrt(rt);
        double cx1 = ((a * x) + y * rt) / (xsq + ysq);
        double cx2 = ((a * x) - y * rt) / (xsq + ysq);
        double cy1 = ((a * y) - x * rt) / (xsq + ysq);
        double cy2 = ((a * y) + x * rt) / (xsq + ysq);
        Complex[] ret = {new Complex(cx1 + c1.c.x, cy1 + c1.c.y), new Complex(cx2 + c1.c.x, cy2 + c1.c.y)};
        return ret;
    }
}


class FastScanner {
    private final InputStream in = System.in;
    private final byte[] buffer = new byte[1024];
    private int ptr = 0;
    private int buflen = 0;

    private boolean hasNextByte() {
        if (ptr < buflen) {
            return true;
        } else {
            ptr = 0;
            try {
                buflen = in.read(buffer);
            } catch (IOException e) {
                e.printStackTrace();
            }
            if (buflen <= 0) {
                return false;
            }
        }
        return true;
    }

    private int readByte() {
        if (hasNextByte()) {
            return buffer[ptr++];
        } else {
            return -1;
        }
    }

    private static boolean isPrintableChar(int c) {
        return 33 <= c && c <= 126;
    }

    public boolean hasNext() {
        while (hasNextByte() && !isPrintableChar(buffer[ptr])) {
            ptr++;
        }
        return hasNextByte();
    }

    public String next() {
        if (!hasNext()) {
            throw new NoSuchElementException();
        }
        StringBuilder sb = new StringBuilder();
        int b = readByte();
        while (isPrintableChar(b)) {
            sb.appendCodePoint(b);
            b = readByte();
        }
        return sb.toString();
    }

    public long nextLong() {
        if (!hasNext()) {
            throw new NoSuchElementException();
        }
        long n = 0;
        boolean minus = false;
        int b = readByte();
        if (b == '-') {
            minus = true;
            b = readByte();
        }
        if (b < '0' || '9' < b) {
            throw new NumberFormatException();
        }
        while (true) {
            if ('0' <= b && b <= '9') {
                n *= 10;
                n += b - '0';
            } else if (b == -1 || !isPrintableChar(b)) {
                return minus ? -n : n;
            } else {
                throw new NumberFormatException();
            }
            b = readByte();
        }
    }

    public int nextInt() {
        long nl = nextLong();
        if (nl < Integer.MIN_VALUE || nl > Integer.MAX_VALUE) {
            throw new NumberFormatException();
        }
        return (int) nl;
    }

    public double nextDouble() {
        return Double.parseDouble(next());
    }
}

class Circle {
    public Complex c;
    public double r;

    public Circle(Complex center, double radius) {
        this.c = center;
        this.r = Math.abs(radius);
    }

    public boolean inon(Complex z) {
        return Complex.dist(c, z) <= r + Const.DELTA;
    }

    public boolean in(Complex z) {
        return Complex.dist(c, z) < r - Const.DELTA;
    }

    public boolean on(Complex z) {
        return inon(z) && !in(z);
    }
}

class Line {
    // a^2 + b^2 = 1.
    public double a, b, c;
    public double t;
    public double lx, rx, ly, ry;
    public Complex begin, end;

    public static Line create(Complex a, Complex b, boolean extendA, boolean extendB) {
        if (a.x > b.x) {
            return new Line(b, a, extendB, extendA);
        } else {
            return new Line(a, b, extendA, extendB);
        }
    }

    public double dist(Complex c) {
        return Math.abs(this.a * c.x + this.b * c.y + this.c);
    }

    public boolean onLine(Complex c) {
        return inDomain(c) && Math.abs(this.a * c.x + this.b * c.y + this.c) < Const.DELTA;
    }

    public boolean inDomain(Complex c) {
        return c.x >= this.lx && c.x <= this.rx && c.y >= this.ly && c.y <= this.ry;
    }

    private Line(Complex a, Complex b, boolean extendA, boolean extendB) {
        this.a = b.y - a.y;
        this.b = a.x - b.x;
        this.c = -a.x * b.y + b.x * a.y;
        double hp = Math.hypot(this.a, this.b);
        this.a /= hp;
        this.b /= hp;
        this.c /= hp;
        if (a.x == b.x) {
            this.t = Const.DINF;
            if (a.y < b.y) {
                if (!extendA) {
                    this.begin = a.clone();
                    this.lx = a.x;
                    this.ly = a.y;
                } else {
                    this.begin = new Complex(this.lx = a.x, this.ly = -Const.DINF);
                }
                if (!extendB) {
                    this.end = b.clone();
                    this.rx = b.x;
                    this.ry = b.y;
                } else {
                    this.end = new Complex(this.rx = b.x, this.ry = Const.DINF);
                }
            }
        } else {
            this.t = (b.y - a.y) / (b.x - a.x);
            if (!extendA) {
                this.begin = a.clone();
                this.lx = a.x;
                this.ly = a.y;
            } else {
                if (t > 0) {
                    if (t >= 1.) {
                        this.begin = new Complex(this.lx = x(-Const.DINF), this.ly = -Const.DINF);
                    } else {
                        this.begin = new Complex(this.lx = -Const.DINF, this.ly = y(-Const.DINF));
                    }
                } else {
                    if (t <= -1.) {
                        this.begin = new Complex(this.lx = x(Const.DINF), this.ly = Const.DINF);
                    } else {
                        this.begin = new Complex(this.lx = -Const.DINF, this.ly = y(-Const.DINF));
                    }
                }
            }
            if (!extendB) {
                this.end = b.clone();
                this.rx = b.x;
                this.ry = b.y;
            } else {
                if (t > 0) {
                    if (t >= 1.) {
                        this.begin = new Complex(this.rx = x(Const.DINF), this.ry = Const.DINF);
                    } else {
                        this.begin = new Complex(this.rx = Const.DINF, this.ry = y(Const.DINF));
                    }
                } else {
                    if (t <= -1.) {
                        this.begin = new Complex(this.rx = x(-Const.DINF), this.ry = -Const.DINF);
                    } else {
                        this.begin = new Complex(this.rx = Const.DINF, this.ry = y(Const.DINF));
                    }
                }
            }
        }
    }

    private double x(double y) {
        return - (b * y + c) / a;
    }

    private double y(double x) {
        return - (a * x + c) / b;
    }
}


class Complex implements Cloneable {
    public static final double PI = Math.PI;
    public static final double E = Math.E;
    public static final Complex ZERO = new Complex(0, 0);
    public static final Complex ONE = new Complex(1, 0);
    public static final Complex I = new Complex(0, 1);
    public static final Complex NaN = new Complex(Double.NaN, Double.NaN);

    public double x;
    public double y;
    public double r;
    public double theta;

    public Complex(double x, double y) {
        this.x = x;
        this.y = y;
        this.r = Math.hypot(x, y);
        this.theta = Math.atan2(y, x);
    }

    public Complex(double r, double theta, boolean radian) {
        this.r = r;
        if (radian) {
            this.theta = theta;
        } else {
            this.theta = Math.toRadians(theta);
        }
        this.x = this.r * Math.cos(this.theta);
        this.y = this.r * Math.sin(this.theta);
    }

    public Complex(double theta, boolean radian) {
        this(1., theta, radian);
    }

    private double re() {
        return x;
    }

    private double im() {
        return y;
    }

    private double abs() {
        return r;
    }

    private double arg() {
        return theta;
    }

    private Complex conj() {
        return new Complex(x, -y);
    }

    private double sin() {
        return Math.sin(arg());
    }

    private double cos() {
        return Math.cos(arg());
    }

    private double tan() {
        return Math.tan(arg());
    }

    private Complex rot(double phi, boolean radian) {
        return new Complex(r, theta + (radian ? phi : Math.toRadians(phi)), true);
    }

    private Complex exp(int n) {
        return new Complex(Math.pow(r, n), theta * n, true);
    }

    private double dist(Complex c) {
        return abs(this.sub(c));
    }

    private double distSq(Complex c) {
        return (c.x - x) * (c.x - x) + (c.y - y) * (c.y - y);
    }

    private Complex add(Complex c) {
        return new Complex(x + c.x, y + c.y);
    }

    private Complex sub(Complex c) {
        return new Complex(x - c.x, y - c.y);
    }

    private Complex mul(Complex c) {
        return new Complex(x * c.x - y * c.y, x * c.y + y * c.x);
    }

    private Complex div(Complex c) {
        double retx, rety;
        if (c.equals(ZERO)) {
            if (x > 0) {
                retx = Double.POSITIVE_INFINITY;
            } else if (x < 0) {
                retx = Double.NEGATIVE_INFINITY;
            } else {
                retx = Double.NaN;
            }
            if (y > 0) {
                rety = Double.POSITIVE_INFINITY;
            } else if (y < 0) {
                rety = Double.NEGATIVE_INFINITY;
            } else {
                rety = Double.NaN;
            }
            return new Complex(retx, rety);
        }
        return mul(div(this, c.r), new Complex(-c.theta, true));
    }

    private Complex add(double r) {
        return new Complex(x + r, y);
    }

    private Complex sub(double r) {
        return new Complex(x - r, y);
    }

    private Complex mul(double r) {
        return new Complex(x * r, y * r);
    }

    private Complex div(double r) {
        return new Complex(x / r, y / r);
    }

    public static Complex conj(Complex c) {
        return c.conj();
    }

    public static double re(Complex c) {
        return c.re();
    }

    public static double im(Complex c) {
        return c.im();
    }

    public static double abs(Complex c) {
        return c.abs();
    }

    public static double arg(Complex c) {
        return c.arg();
    }

    public static double sin(Complex c) {
        return c.sin();
    }

    public static double cos(Complex c) {
        return c.cos();
    }

    public static double tan(Complex c) {
        return c.tan();
    }

    public static Complex rot(Complex c, double phi, boolean radian) {
        return c.rot(phi, radian);
    }

    public static Complex exp(Complex c, int n) {
        return c.exp(n);
    }

    public static double dist(Complex a, Complex b) {
        return a.dist(b);
    }

    public static double distSq(Complex a, Complex b) {
        return a.distSq(b);
    }

    public static Complex[] nthRoot(int n) {
        Complex[] ret = new Complex[n];
        for (int i = 0; i < n; i++) {
            ret[i] = new Complex(2. * PI * i / n, true);
        }
        return ret;
    }

    public static Complex add(Complex... c) {
        Complex ret = ZERO;
        for (Complex b : c) {
            ret = ret.add(b);
        }
        return ret;
    }

    public static Complex sub(Complex a, Complex b) {
        return a.sub(b);
    }

    public static Complex mul(Complex... c) {
        Complex ret = ONE;
        for (Complex b : c) {
            ret = ret.mul(b);
        }
        return ret;
    }

    public static Complex div(Complex a, Complex b) {
        return a.div(b);
    }

    public static Complex add(double r, Complex... c) {
        return add(c).add(r);
    }

    public static Complex add(Complex c, double r) {
        return c.add(r);
    }

    public static Complex sub(Complex a, double r) {
        return a.sub(r);
    }

    public static Complex mul(double r, Complex... c) {
        return mul(c).mul(r);
    }

    public static Complex mul(Complex c, double r) {
        return c.mul(r);
    }

    public static Complex div(Complex a, double r) {
        return a.div(r);
    }

    public boolean isNaN() {
        return Double.isNaN(x) || Double.isNaN(y);
    }

    private Complex(double x, double y, double r, double theta) {
        this.x = x;
        this.y = y;
        this.r = r;
        this.theta = theta;
    }

    @Override
    public Complex clone() {
        return new Complex(this.x, this.y, this.r, this.theta);
    }

    @Override
    public boolean equals(Object o) {
        if (o == this) {
            return true;
        } else if (o instanceof Complex) {
            Complex c = (Complex) o;
            if (c.x == this.x && c.y == this.y && c.r == this.r && c.theta == this.theta) {
                return true;
            } else {
                return false;
            }
        } else {
            return false;
        }
    }

    @Override
    public int hashCode() {
        return Objects.hash(x, y, r, theta);
    }

    @Override
    public String toString() {
        return x + " + i*" + y + ", " + r + "*e^i*" + theta;
    }
}

class Const {
    public static final long MOD7 = 1_000_000_007;
    public static final long MOD9 = 1_000_000_009;
    public static final long MOD99 = 998_244_353;
    public static long MOD = MOD7;

    public static final long LINF = 1_000_000_000_000_000_000l;
    public static final int IINF = 1_000_000_000;
    public static final double DINF = 1e150;

    public static final double DELTA = 0.0000000001;

    public static void setMod(long mod) {
        MOD = mod;
    }
}

class Triangle {
    public Complex[] c = new Complex[3];
    public double[] angle = new double[3];
    public double[] length = new double[3];

    public Triangle(Complex a, Complex b, Complex c) {
        this.c[0] = a;
        this.c[1] = b;
        this.c[2] = c;
        for(int i = 0; i < 3; i++) {
            this.angle[i] = Geometry.arg(this.c[(i + 2) % 3], this.c[i], this.c[(i + 1) % 3]);
            if (this.angle[i] > Math.PI) {
                this.angle[i] = 2. * Math.PI - this.angle[i];
            }
            this.length[i] = Complex.dist(this.c[(i + 1) % 3], this.c[(i + 2) % 3]);
        }
    }

    public Complex pG() {
        if (!isTriangle()) {
            return null;
        }
        return Complex.div(Complex.add(c), 3.);
    }

    public Complex pH() {
        if (!isTriangle()) {
            return null;
        }
        Complex pO = pO();
        return Complex.add(Complex.sub(c[0], pO), Complex.sub(c[1], pO), Complex.sub(c[2], pO), pO);
    }

    public Complex pI() {
        if (!isTriangle()) {
            return null;
        }
        double la = Complex.dist(c[1], c[2]);
        double lb = Complex.dist(c[2], c[0]);
        double lc = Complex.dist(c[0], c[1]);
        return Complex.div(Complex.add(Complex.mul(c[0], la), Complex.mul(c[1], lb), Complex.mul(c[2], lc)), la + lb + lc);
    }

    public Complex pO() {
        if (!isTriangle()) {
            return null;
        }
        double la = Complex.distSq(c[1], c[2]);
        double lb = Complex.distSq(c[2], c[0]);
        double lc = Complex.distSq(c[0], c[1]);
        double sa = la * (lb + lc - la);
        double sb = lb * (lc + la - lb);
        double sc = lc * (la + lb - lc);
        return Complex.div(Complex.add(Complex.mul(c[0], sa), Complex.mul(c[1], sb), Complex.mul(c[2], sc)), sa + sb + sc);
    }

    public Complex[] pIabc() {
        if (!isTriangle()) {
            return null;
        }
        Complex[] pIabc = new Complex[3];
        pIabc[0] = Geometry.pI(Complex.mul(c[0], -1.), c[1], c[2]);
        pIabc[1] = Geometry.pI(c[0], Complex.mul(c[1], -1.), c[2]);
        pIabc[2] = Geometry.pI(c[0], c[1], Complex.mul(c[2], -1.));
        return pIabc;
    }

    public boolean isTriangle() {
        return !Geometry.oneLine(c[0], c[1], c[2]);
    }

    public double area() {
        return Math.abs(((c[0].x - c[2].x) * (c[1].y - c[2].y) - (c[1].x - c[2].x) * (c[0].y - c[2].y))/2.);
    }
}
