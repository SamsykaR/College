package com.example.guessinggame

import android.os.Bundle
import androidx.navigation.NavDirections
import kotlin.Int
import kotlin.String

public class GameFragmentDirections private constructor() {
  private data class ActionGameFragmentToResultFragment(
    public val result: String,
  ) : NavDirections {
    public override val actionId: Int = R.id.action_gameFragment_to_resultFragment

    public override val arguments: Bundle
      get() {
        val result = Bundle()
        result.putString("result", this.result)
        return result
      }
  }

  public companion object {
    public fun actionGameFragmentToResultFragment(result: String): NavDirections =
        ActionGameFragmentToResultFragment(result)
  }
}
