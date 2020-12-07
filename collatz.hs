{-# OPTIONS_GHC -fno-warn-incomplete-patterns #-}

--DONE 1/9
f :: Integer -> Integer
f 1 = 1
f x
 |even x = x `div` 2
 |odd x = 3*x+1


--DONE 2/9
applyTo :: Integer -> [Integer]
applyTo 1 = repeat 1
applyTo n =  n : applyTo (f n)

 
--DONE 3/9
cutRepeated :: Eq a => [a] -> [a]
cutRepeated (x:y:xs)
 | x == y = [y]
 | otherwise = x : cutRepeated (y:xs)


--DONE 4/9
reducedApplyTo :: Integer -> [Integer] 
reducedApplyTo 1 = [1]
reducedApplyTo n =  n : reducedApplyTo (f n)


--DONE 5/9
runSize :: Integer -> Int
runSize n = length(reducedApplyTo n)


--DONE 6/9
runSizes :: [Int] 
runSizes = [runSize n | n<-[1..]]


--DONE 7/9
increasingly :: (a -> a -> Bool) -> [a] -> [a]
increasingly fgv (x:y:z:rest)
 | fgv x y && fgv y z = x : y : z : increasingly fgv (z:rest)
 | fgv x y && not(fgv y z) = y : increasingly fgv (y:z:rest)
 | otherwise = [] 
  

 --DONE 8/9
increasingSizes :: [Int]  -- Balazs kerese alapjan
increasingSizes = increasingly (<) runSizes

--alapverzio
getGreater :: Int -> [Int] -> [Int]
getGreater n (x:xs)
 | x > n = x : getGreater x xs
 | otherwise = getGreater n xs
 
increasingSizes' :: [Int]
increasingSizes' = getGreater (-1) runSizes


--DONE 9/9
getLongerLists :: Int -> [Int] -> [Integer]
getLongerLists n (x:xs)
 | runSize (toInteger x) > n = toInteger x : getLongerLists (runSize (toInteger x)) xs
 | otherwise = getLongerLists n xs

increasingNumbersByRun :: [Integer]
increasingNumbersByRun = getLongerLists (-1) [1..]
