
import Data.List
----------------------------------------------------------------PREDEFINED
type Dictionary = [(Char, Integer)]
dictionary :: [Char] -> Dictionary
dictionary x = zip x [1..]


dictionary_az_AZ = [('a', 1), ('b', 2), ('c', 3), ('d', 4), ('e', 5), ('f', 6),
                    ('g', 7), ('h', 8), ('i', 9), ('j', 10), ('k', 11), ('l', 12),
                    ('m', 13), ('n', 14), ('o', 15), ('p', 16), ('q', 17), ('r', 18),
                    ('s', 19), ('t', 20), ('u', 21), ('v', 22), ('w', 23), ('x', 24),
                    ('y', 25), ('z', 26), ('A', 27), ('B', 28), ('C', 29), ('D', 30),
                    ('E', 31), ('F', 32), ('G', 33), ('H', 34), ('I', 35), ('J', 36),
                    ('K', 37), ('L', 38), ('M', 39), ('N', 40), ('O', 41), ('P', 42),
                    ('Q', 43), ('R', 44), ('S', 45), ('T', 46), ('U', 47), ('V', 48),
                    ('W', 49), ('X', 50), ('Y', 51), ('Z', 52)] :: Dictionary

dictionary_az = [('a', 1), ('b', 2), ('c', 3), ('d', 4), ('e', 5), ('f', 6),
                 ('g', 7), ('h', 8), ('i', 9), ('j', 10), ('k', 11), ('l', 12),
                 ('m', 13), ('n', 14), ('o', 15), ('p', 16), ('q', 17), ('r', 18),
                 ('s', 19), ('t', 20), ('u', 21), ('v', 22), ('w', 23), ('x', 24),
                 ('y', 25), ('z', 26)] :: Dictionary


isPrime :: Integer -> Bool
isPrime 0 = False
isPrime 1 = False
isPrime 2 = True
isPrime n = odd n && null [d | d <- [3,5..squareRoot n], n `mod` d == 0] where
  squareRoot :: Integer -> Integer
  squareRoot n = floor (sqrt (fromIntegral n))


primeList :: [Integer]
primeList = 2:[ x | x <- [3,5..], isPrime x]
----------------------------------------------------------------PREDEFINED ENDS

----------------------------------------------------------------USER DEFINED
charToNum :: Dictionary -> Char -> Integer
charToNum [] char_to_find = 0
charToNum ((key,value):rest_of_dict) char_to_find
 | key == char_to_find = value
 | otherwise = charToNum rest_of_dict char_to_find


numToChar :: Dictionary -> Integer -> Char
numToChar [] number_to_find = '*'
numToChar ((key,value):rest_of_number) number_to_find
 | value == number_to_find = key
 | otherwise = numToChar rest_of_number number_to_find


translate :: Dictionary -> String -> [Integer]
translate dict [] = []
translate dict (letter:rest_of_string) = charToNum dict letter : translate dict rest_of_string


encode :: Dictionary -> String -> Integer
encode [] string_to_encode = 1
encode dict "" = 1
encode dict string_to_encode = product[(primeList !! prime)^char_in_digits | let x = (translate dict string_to_encode),(prime, char_in_digits)<-(zip [0..] x)]

smallestPrimeDivisor :: Integer -> Integer
smallestPrimeDivisor szam = head [x | x<-[2..szam], szam `mod` x==0, isPrime x]

primeFactorization :: Integer -> [Integer]
primeFactorization 1 = []
primeFactorization number_to_factorize = (smallestPrimeDivisor number_to_factorize) : primeFactorization (number_to_factorize `div` (smallestPrimeDivisor number_to_factorize)) 


decode :: Dictionary -> Integer -> String 
decode dict number_to_decode = [current_char | chars<- [x | char_in_digits<-group (primeFactorization number_to_decode), let x = toInteger (length char_in_digits)], let current_char = numToChar dict chars]
