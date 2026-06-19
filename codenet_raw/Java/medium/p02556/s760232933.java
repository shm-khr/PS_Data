import java.io.IOException;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.ArrayList;

public class Main {
    private static final StringBuilder builder = new StringBuilder();
    public static void main(String[] args) {
        long n = readLong();
        long ppMax = 0, ppMin = Long.MAX_VALUE, pnMax = 0, pnMin = Long.MAX_VALUE,
                npMax = 0, npMin = Long.MAX_VALUE, nnMax = 0, nnMin = Long.MAX_VALUE;
        Pair ppMaxPair = null, pnMaxPair = null, npMaxPair = null, nnMaxPair = null,
                ppMinPair = null, pnMinPair = null, npMinPair = null, nnMinPair = null;
        for (long l = 0; l < n; l++) {
            long x = readLong(), y = readLong();
            Pair p = new Pair(x, y);
            long man = Math.abs(x) + Math.abs(y);
            if (x >= 0 && y >= 0) {
                if (man >= ppMax) {
                    ppMax = man;
                    ppMaxPair = p;
                }
                
                if (man <= ppMin) {
                    ppMin = man;
                    ppMinPair = p;
                }
            } else if (x >= 0) {
                if (man >= pnMax) {
                    pnMax = man;
                    pnMaxPair = p;
                }

                if (man <= pnMin) {
                    pnMin = man;
                    pnMinPair = p;
                }
            } else if (y >= 0) {
                if (man >= npMax) {
                    npMax = man;
                    npMaxPair = p;
                }

                if (man <= npMin) {
                    npMin = man;
                    npMinPair = p;
                }
            } else {
                if (man >= nnMax) {
                    nnMax = man;
                    nnMaxPair = p;
                }

                if (man <= nnMin) {
                    nnMin = man;
                    nnMinPair = p;
                }
            }
        }
        
        ArrayList<Pair> pairs = new ArrayList<>();
        if (ppMaxPair != null) pairs.add(ppMaxPair);
        if (pnMaxPair != null) pairs.add(pnMaxPair);
        if (npMaxPair != null) pairs.add(npMaxPair);
        if (nnMaxPair != null) pairs.add(nnMaxPair);
        if (ppMinPair != null) pairs.add(ppMinPair);
        if (pnMinPair != null) pairs.add(pnMinPair);
        if (npMinPair != null) pairs.add(npMinPair);
        if (nnMinPair != null) pairs.add(nnMinPair);

        long max = 0;
        while (pairs.size() > 1) {
            Pair p = pairs.remove(0);
            for (Pair pair : pairs) {
                if (max < p.man(pair)) max = p.man(pair);
            }
        }

        System.out.print(max);
        
    }
    
    private static class Pair {
        long x;
        long y;
        public Pair(long x, long y) {
            this.x = x;
            this.y = y;
        }
        
        public long man(Pair p) {
            return Math.abs(x - p.x) + Math.abs(y - p.y);
        }
    }

    private static void read() {
        builder.setLength(0);
        while (true) {
            try {
                int b = System.in.read();
                if (b == ' ' || b == '\n' || b == -1) {
                    break;
                } else {
                    builder.appendCodePoint(b);
                }
            } catch (IOException e) {
                break;
            }
        }
    }

    private static int readInt() {
        read();
        return Integer.parseInt(builder.toString());
    }

    private static int readInt(int radix) {
        read();
        return Integer.parseInt(builder.toString(), radix);
    }

    private static long readLong() {
        read();
        return Long.parseLong(builder.toString());
    }

    private static long readLong(int radix) {
        read();
        return Long.parseLong(builder.toString(), radix);
    }

    private static BigInteger readBigInteger() {
        read();
        return new BigInteger(builder.toString());
    }

    private static BigInteger readBigInteger(int radix) {
        read();
        return new BigInteger(builder.toString(), radix);
    }

    private static double readDouble() {
        read();
        return Double.parseDouble(builder.toString());
    }

    private static BigDecimal readBigDecimal() {
        read();
        return new BigDecimal(builder.toString());
    }

    private static float readFloat() {
        read();
        return Float.parseFloat(builder.toString());
    }

    private static void skipLine() {
        while (true) {
            try {
                int b = System.in.read();
                if (b == '\n' || b == -1) {
                    break;
                }
            } catch (IOException e) {
                break;
            }
        }
    }

    private static void skip() {
        while (true) {
            try {
                int b = System.in.read();
                if (b == ' ' || b == '\n' || b == -1) break;
            } catch (IOException e) {
                break;
            }
        }
    }

}
