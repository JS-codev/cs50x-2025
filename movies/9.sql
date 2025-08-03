SELECT DISTINCT people.name FROM people
JOIN directors ON people.id = directors.person_id
JOIN movies ON directors.movie_id = movies.id
JOIN stars ON movies.id = stars.movie_id
JOIN people AS hanks ON stars.person_id = hanks.id
WHERE hanks.name = 'Tom Hanks';
