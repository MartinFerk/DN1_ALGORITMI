# Uporabi osnovno sliko z g++
FROM gcc:latest

# Ustvari delovno mapo v kontejnerju
WORKDIR /app

# Kopiraj main.cpp v delovno mapo
COPY main.cpp .

# Prevedi program v datoteko z imenom "program"
RUN g++ main.cpp -o program

# Privzeto zaženi program
CMD ["./program"]
