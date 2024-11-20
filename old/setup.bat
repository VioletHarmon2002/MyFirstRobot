docker build --tag little-endian .
docker run --publish 80:80 --publish 8080:8080 --detach little-endian