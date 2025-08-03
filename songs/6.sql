SELECT s.name
FROM songs s
JOIN artists a ON s.artist_id = a.artist_id
WHERE a.name = 'Post Malone';
