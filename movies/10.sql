SELECT DISTINCT d.name FROM people AS d
JOIN directors ON d.id = directors.person_id
JOIN movies ON directors.movie_id = movies.id
JOIN stars ON movies.id = stars.movie_id
JOIN people AS kb ON stars.person_id = kb.id
WHERE kb.name = 'Kevin Bacon';
