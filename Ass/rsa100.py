import math
def isPrime(n):
  for i in range(2,int(math.sqrt(n))+1):
    if n%i==0:
      return False
  return True
def SieveOfEratosthenes(num,rsanumber):
  prime = [True for i in range(num+1)]
  p = 2
  while (p * p <= num):
    # If prime[p] is not
    # changed, then it is a prime
    if (prime[p] == True):
      # Updating all multiples of p
      for i in range(p * p, num+1, p):
        prime[i] = False
    p += 1
  # Print all prime numbers
  for p in range(2, num+1):
    if prime[p]:
      print(p,"A")
      if rsanumber%p==0:
        #print(p,"B")
        if isPrime(rsanumber/p):
          print(p," ",int(rsanumber/p)," ",rsanumber)
          break
      
# Driver code
if __name__ == '__main__':
  #num = 1522605027922533360535618378132637429718068114961380688657908494580122963258952897654000350692006139
  num = 6
  print("Following are the prime numbers smaller"),
  print("than or equal to", num)
  SieveOfEratosthenes(int(math.sqrt(num))+1,num) 





