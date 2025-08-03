SELECT year FROM movies
JOIN ratings ON movies.id = ratings.movie_id
WHERE rating >= 9.0;
