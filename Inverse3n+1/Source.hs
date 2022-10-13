import Text.Read (readMaybe)
tnpo :: Int -> [Int]
tnpo n = if n /= 0
            then if odd ((n - 1) `div` 3) && n /= 4
               then [n * 2, (n - 1) `div` 3]
               else [n * 2]
            else []

atnpo :: Int -> [Int]
atnpo i = if i == 0
             then [1]
             else concatMap tnpo $ atnpo $ i - 1

main :: IO ()
main = do
    putStrLn "Iterations of inverse 3n+1?"
    inp1 <- getLine
    let n = read inp1 :: Int
    let arr = atnpo n
    --putStrLn "\nArray:"
    --print arr
    putStrLn "\nLength:"
    print $ length arr
