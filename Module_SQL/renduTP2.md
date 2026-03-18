
17. 
```sql
SELECT p.nom, p.prenom
FROM personne p
WHERE NOT EXISTS (
    SELECT 1
    FROM acteur a
    WHERE a.numpersonne = p.numpersonne
);
```

18. 
```sql
SELECT f.titre
FROM film f
WHERE f.numfilm NOT IN (
    SELECT pr.numfilm
    FROM programmation pr
         INNER JOIN cinema ci ON pr.numcinema = ci.numcinema
    WHERE ci.compagnie = 'indep'
);
```

19. 
```sql
SELECT f.titre
FROM film f
WHERE NOT EXISTS (
    SELECT 1
    FROM salle s
    WHERE NOT EXISTS (
        SELECT 1
        FROM programmation p
        WHERE p.numcinema = s.numcinema
          AND p.numsalle  = s.numsalle
          AND p.numfilm   = f.numfilm
    )
);      
```

20. 
```sql
SELECT f.titre
FROM film f
WHERE NOT EXISTS (
    SELECT 1
    FROM cinema c
    WHERE NOT EXISTS (
        SELECT 1
        FROM programmation p
        WHERE p.numcinema = c.numcinema
          AND p.numfilm   = f.numfilm
    )
);
```

21. 
```sql
SELECT pers.nom, pers.prenom
FROM personne pers
JOIN acteur ac ON pers.numpersonne = ac.numpersonne
JOIN distribution d ON ac.numacteur = d.numacteur
JOIN film f ON d.numfilm = f.numfilm
WHERE f.realisateur = (
      SELECT numpersonne
      FROM personne
      WHERE nom='Hazanavicius'
        AND prenom='Michel'
)
GROUP BY pers.nom, pers.prenom
HAVING COUNT(DISTINCT f.numfilm) =
(
    SELECT COUNT(*)
    FROM film
    WHERE realisateur = (
        SELECT numpersonne
        FROM personne
        WHERE nom='Hazanavicius'
          AND prenom='Michel'
    )
);
```

22. 
```sql
SELECT p.nom, p.prenom
FROM personne p
JOIN film f ON p.numpersonne = f.realisateur
WHERE f.salaire_real > (
    SELECT MAX(d.salaire)
    FROM distribution d
    WHERE d.numfilm = f.numfilm
);
```

