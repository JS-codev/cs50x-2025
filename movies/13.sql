SELECT DISTINCT people.name FROM people
JOIN stars ON people.id = stars.person_id
JOIN movies ON stars.movie_id = movies.id
JOIN directors ON movies.id = directors.movie_id
JOIN people AS d ON directors.person_id = d.id
WHERE d.name = 'Christopher Nolan';
