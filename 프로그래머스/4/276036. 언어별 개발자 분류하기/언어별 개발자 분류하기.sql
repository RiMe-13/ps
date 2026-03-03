-- 코드를 작성해주세요
WITH GRADED_DEVS AS (
    SELECT 
        ID,
        EMAIL,
        CASE 
            -- A등급: Front End 스킬 보유 AND Python 스킬 보유
            WHEN (SKILL_CODE & (SELECT SUM(CODE) FROM SKILLCODES WHERE CATEGORY = 'Front End')) > 0 
                 AND (SKILL_CODE & (SELECT CODE FROM SKILLCODES WHERE NAME = 'Python')) > 0 THEN 'A'
            
            -- B등급: C# 스킬 보유
            WHEN (SKILL_CODE & (SELECT CODE FROM SKILLCODES WHERE NAME = 'C#')) > 0 THEN 'B'
            
            -- C등급: 그 외의 Front End 개발자
            WHEN (SKILL_CODE & (SELECT SUM(CODE) FROM SKILLCODES WHERE CATEGORY = 'Front End')) > 0 THEN 'C'
        END AS GRADE
    FROM 
        DEVELOPERS
)

SELECT 
    GRADE, 
    ID, 
    EMAIL
FROM 
    GRADED_DEVS
WHERE 
    GRADE IS NOT NULL
ORDER BY 
    GRADE ASC, 
    ID ASC;