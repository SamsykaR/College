package com.example.guessinggame

import android.os.Bundle
import androidx.fragment.app.Fragment
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import com.example.guessinggame.databinding.FragmentGameBinding
import androidx.navigation.findNavController
// Провайдер модели представления
import androidx.lifecycle.ViewModelProvider

class GameFragment : Fragment() {
    // Используются для связывания представлений
    private var _binding: FragmentGameBinding? = null
    private val binding get() = _binding!!
    // Добавляем свойство viewModel (lateinit означает, что будет инициализировано позднее).
    private lateinit var viewModel: GameViewModel

    override fun onCreateView( //метод при создании активности
        inflater: LayoutInflater, container: ViewGroup?,
        savedInstanceState: Bundle?
    ): View {
        _binding = FragmentGameBinding.inflate(inflater, container, false)
        val view = binding.root
        // Задаем свойство viewModel
        viewModel = ViewModelProvider(this)[GameViewModel::class.java]
        updateScreen()
        binding.guessButton.setOnClickListener {
            // Вызываем makeGuess, чтобы обработать предположение пользователя.
            viewModel.makeGuess(binding.guess.text.toString().uppercase())
            // Очистить текстовое поле и обновить экран.
            binding.guess.text = null
            updateScreen()

            if (viewModel.isWon() || viewModel.isLost()) {
                val action = GameFragmentDirections
                    .actionGameFragmentToResultFragment(viewModel.wonLostMessage())
                view.findNavController().navigate(action)
            }
        }
        return view
    }

    // Если макет стал недоступным для его фрагмента, свойству _binding присваивается null.
    override fun onDestroyView() {
        super.onDestroyView()
        _binding = null
    }

    // Задаем содержимое текстовых представлений макета.
    private fun updateScreen() {
        binding.word.text = viewModel.secretWordDisplay
        binding.lives.text = buildString {
            append("У тебя есть ")
            append(viewModel.livesLeft)
            append(" оставшиеся жизни.")
        }
        binding.incorrectGuesses.text = buildString {
            append("Неверные догадки: ")
            append(viewModel.incorrectGuesses)
        }
    }
}