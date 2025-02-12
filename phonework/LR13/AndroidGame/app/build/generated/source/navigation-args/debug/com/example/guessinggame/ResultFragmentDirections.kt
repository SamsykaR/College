package com.example.guessinggame

import androidx.navigation.ActionOnlyNavDirections
import androidx.navigation.NavDirections

public class ResultFragmentDirections private constructor() {
  public companion object {
    public fun actionResultFragmentToGameFragment(): NavDirections =
        ActionOnlyNavDirections(R.id.action_resultFragment_to_gameFragment)
  }
}
