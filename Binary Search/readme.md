## Algorithm
```
Binary(DATA, LB, UB, ITEM, LOC)

Step1: Set BEG:= LB; END:= UB and MID = int(BEG + END)/2
Step 2: Repeat step 3&4, while BEG <= END and DATA[MID] != ITEM
Step 3: if ITEM < DATA[MID] then,
		Set END:= MID - 1
	else:
		Set BEG:= MID + 1
	end if;
Step 4: Set MID:=int(BEG + END)/2
	end of Step2;
Step 5: if ITEM = DATA[MID] then
		Set LOC:= MID
	else
		Set LOC:= Null
	Print LOC
	end if;
Step 6: Exit
```


## Output
![binary](https://user-images.githubusercontent.com/44961536/189518214-45eab7a5-ee2b-4450-afea-25643c11f663.jpg)
