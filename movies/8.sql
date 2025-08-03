SELECT DISTINCT p1.name FROM people p1
JOIN stars s1 ON p1.id = s1.person_id
JOIN movies m1 ON s1.movie_id = m1.id
WHERE m1.id IN (
    SELECT m2.id FROM movies m2
    JOIN stars s2 ON m2.id = s2.movie_id
    JOIN people p2 ON s2.person_id = p2.id
    WHERE p2.name = 'Johnny Depp'
)
AND m1.id IN (
    SELECT m3.id FROM movies m3
    JOIN stars s3 ON m3.id = s3.movie_id
    JOIN people p3 ON s3.person_id = p3.id
    WHERE p3.name = 'Helena Bonham Carter'
);
