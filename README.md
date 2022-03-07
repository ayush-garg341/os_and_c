# os_and_c

### Running c files on mac through docker. 
docker build -t os_anc_c .
docker-compose up -d
docker exec -it <container_id> /bin/sh
gcc <file_name.c>
