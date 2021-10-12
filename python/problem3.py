# Problem 3 - Use string functions


s = "python  is more preferred in IIIT DWD"

s = s.replace("python","c++")

index = s.find( "IIIT DWD" )
if "IIIT DWD" in s:
    print("Institute found")
print(s,"\n", index)