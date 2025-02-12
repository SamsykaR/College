package com.example.guessinggame

import androidx.lifecycle.ViewModel
class GameViewModel : ViewModel() {
    val words = listOf("Apple", "Orange", "Video") //набор слов для игры
    val secretWord = words.random().uppercase() //случайное слово из списка
    var secretWordDisplay = "" //отображаемое слово
    var correctGuesses = "" //верные буквы
    var incorrectGuesses = "" //ошибочные буквы
    var livesLeft = 8 // количество жизней

    init {
        secretWordDisplay = deriveSecretWordDisplay()
    }

    fun deriveSecretWordDisplay() : String { //обновление выводимого слова
        var display = "" //отображаемое слово
        secretWord.forEach {
            display += checkLetter(it.toString()) //обновление отоброжаемого слова
        }
        return display //возвращает вывод
    }

    fun checkLetter(str: String) = when (correctGuesses.contains(str)) { //функция для проверки буквы
        true -> str //вернуть букву если есть
        false ->"_" //вернуть прочерк если нет
    }
    fun makeGuess(guess: String) { //обработка ввода пользователя
        if (guess.length == 1) {
            if (secretWord.contains(guess)) {
                correctGuesses += guess
                secretWordDisplay = deriveSecretWordDisplay()
            } else {
                incorrectGuesses += "$guess "
                livesLeft--
            }
        }
    }

    fun isWon() = secretWord.equals(secretWordDisplay, true) //условия победы
    fun isLost() = livesLeft <= 0 //условия поражения
    fun wonLostMessage() : String { //сообщение о проигрыше/выигрыше
        var message = "" //сообщение
        if (isWon()) message = "You won!" //сообщение о победе если победа
        else if (isLost()) message = "You lost!" //сообщение о проигрыше если проигрыш
        message += " The word was $secretWord."
        return message
    }
}