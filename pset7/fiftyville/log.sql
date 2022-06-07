-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Get the name of the theif
SELECT name FROM people
-- Get license plate from person that fled from the scene on that certain day
WHERE people.license_plate IN (
    SELECT license_plate FROM bakery_security_logs
    WHERE year = 2021
    AND month = 7
    AND day = 28
    AND hour = 10
    AND minute > 15
    AND minute < 25
)
-- Get person id of who used the atm on Leggett Street like a witness said
AND people.id IN (
    SELECT person_id FROM bank_accounts
    JOIN atm_transactions ON atm_transactions.account_number = bank_accounts.account_number
    WHERE atm_transactions.year = 2021
    AND atm_transactions.month = 7
    AND atm_transactions.day = 28
    AND transaction_type = "withdraw"
    AND atm_transactions.atm_location = "Leggett Street"
)
-- Get phone number of person who was on a call the day of the incident for less than a min
AND people.phone_number IN (
    SELECT caller FROM phone_calls
    WHERE year = 2021
    AND month = 7
    AND day = 28
    AND duration < 60
)
-- Get persons passport number if they took the first flight the day after the incident
AND people.passport_number IN (
    SELECT passport_number FROM passengers
    WHERE flight_id IN (
        SELECT id FROM flights
        WHERE year = 2021
        AND month = 7
        AND day = 29
        ORDER BY hour, minute ASC
        LIMIT 1
    )
)
;

-- Get city destination of the first flight out on the day after the incident
SELECT city FROM airports
WHERE id IN (
    SELECT destination_airport_id FROM flights WHERE year = 2021
    AND month = 7
    AND day = 29
    ORDER BY hour, minute ASC
    LIMIT 1
);

-- Get persons name if they had a call the day of the incident with Bruce for less than a min
SELECT name FROM people
WHERE phone_number IN (
    SELECT receiver FROM phone_calls
    WHERE year = 2021
    AND month = 7
    AND day = 28
    AND caller = (
        SELECT phone_number FROM people WHERE name = "Bruce"
    )
    And duration < 60
);