SELECT AVG(s.energy) AS average_energy
FROM songs s
JOIN artists a ON s.artist_id = a.artist_id
WHERE a.name = 'Drake';
