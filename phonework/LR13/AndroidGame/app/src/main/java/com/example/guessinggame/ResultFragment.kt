package com.example.guessinggame

import android.os.Bundle
import androidx.fragment.app.Fragment
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import com.example.guessinggame.databinding.FragmentResultBinding
import androidx.navigation.findNavController

class ResultFragment : Fragment() {
    // В этом фрагменте также будет использоваться связывание представлений.
    private var _binding: FragmentResultBinding? = null //связь с макетом
    private val binding get() = _binding!! //доступ к связи

    override fun onCreateView( //метод при создании активности
        inflater: LayoutInflater, container: ViewGroup?, savedInstanceState: Bundle?
    ): View? {
        _binding = FragmentResultBinding.inflate(inflater, container, false)
        val view = binding.root

        // Текстовое представление заполняется строкой, переданной из GameFragment
        binding.wonLost.text = ResultFragmentArgs.fromBundle(requireArguments()).result

        binding.newGameButton.setOnClickListener { //событие при нажатии на кнопку
            view.findNavController()
                // По щелчку на кнопке происходит переход к GameFragment.
                .navigate(R.id.action_resultFragment_to_gameFragment)
        }
        return view
    }
    override fun onDestroyView() { //метод при уничтожении активности
        super.onDestroyView()
        _binding = null
    }
}