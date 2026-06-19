 import Control.Applicative
import Control.Monad
import Debug.Trace

data Vector2 = V Double Double deriving Show

main = do
  [x1,y1,x2,y2] <- map read.words<$>getLine
  q <- readLn
  replicateM_ q (solve (V x1 y1) (V x2 y2))

solve :: Vector2 -> Vector2 -> IO ()
solve p1 p2 = do
  [x,y] <- map read.words<$>getLine
  let vecp = add (V x y) (negV p1)
      vecb = add p2 (negV p1)
      inner = dot vecp vecb :: Double
      size  = norm vecb :: Double
  traceShow (x,vecp,size) $ showPoint $ add p1 $ scalar (inner/size) $ scalar (1/size) vecb

showPoint :: Vector2 -> IO ()
showPoint (V x y) = putStrLn $ show x ++ " " ++ show y

add :: Vector2 -> Vector2 -> Vector2
add (V x1 y1) (V x2 y2) = V (x1+x2) (y1+y2)

negV :: Vector2 -> Vector2
negV (V x y) = V (negate x) (negate y)

dot :: Vector2 -> Vector2 -> Double
dot (V x1 y1) (V x2 y2) = x1*x2 + y1*y2

scalar :: Double -> Vector2 -> Vector2
scalar a (V x y) = V (a*x) (a*y)

norm :: Vector2 -> Double
norm (V x y) = sqrt $ x^2 + y^2