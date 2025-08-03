SELECT title, year FROM movies
JOIN stars ON movies.id = stars.movie_id
JOIN people ON stars.person_id = people.id
WHERE people.name = 'Tom Hanks'
ORDER BY year;
