SELECT ANIMAL_ID, NAME,
IF(SEX_UPON_INTAKE LIKE '%NEUTERED%' OR SEX_UPON_INTAKE LIKE '%SPAYED%','O','X') AS '중성화'
FROM ANIMAL_INS
ORDER BY ANIMAL_ID ASC