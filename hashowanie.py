import hashlib


dane1 = "Ala ma kot"
dane2 = "Ala ma psa"


md5 = hashlib.md5(dane1.encode()).hexdigest()

sha256 = hashlib.sha256(dane1.encode()).hexdigest()


print("MD5 (Ala ma kota):   ", md5)
print("SHA-256 (Ala ma kota):", sha256)
